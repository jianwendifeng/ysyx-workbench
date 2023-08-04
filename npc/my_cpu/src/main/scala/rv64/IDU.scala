package rv64

import chisel3._
import chisel3.util._
import ALU_Signals._

class IDUIO(Xlen: Int) extends Bundle{
    val inst = Input(UInt(32.W))

    val alu_sel = Output(UInt(4.W))
    val rd = Output(UInt(5.W))
    // val alu_fun3 = Output(UInt(3.W))
    //val immR = Output(UInt(7.W))
    val a = Output(UInt(Xlen.W))
    val b = Output(UInt(Xlen.W))
}

class IDU(Xlen: Int) extends Module{
    val io = IO(new IDUIO(Xlen))
    val decode = Module(new Decode(Xlen))

    // val op = io.inst(6,0)
    val alu_sel = 0.U(4.W)
    val rd = io.inst(11,7)
    val src1 = io.inst(19,15)
    val src2 = io.inst(24,20)
    // val funct3 = io.inst(14,12)
    //val immR = io.inst(31,25)
    val ren = RegInit(false.B)
    val wen = RegInit(false.B)

    decode.io.inst <> io.inst
    // decode.io.alu_sel <> alu_sel
    decode.io.rf_en <> ren
    decode.io.wb_en <> wen
    

    val imm_s = Cat(io.inst(31,25),io.inst(11,7))
    val imm_s_sext = Cat(Fill(20,imm_s(11)),imm_s)

    val a = RegInit(0.U(Xlen.W))
    val b = RegInit(0.U(Xlen.W))

    //ren := Mux(decode.io.alu_sel === ALU_ADD,true.B, false.B)

    val regFileInst = Module(new rv64.RegFile(Xlen))
    
    regFileInst.io.raddr1 := src1
    regFileInst.io.raddr2 := src2
    a := regFileInst.io.rdata1
    b := regFileInst.io.rdata2
    regFileInst.io.ren := ren
    regFileInst.io.wen := wen
    regFileInst.io.waddr := rd
    regFileInst.io.wdata := 0.U

    io.alu_sel := decode.io.alu_sel
    io.rd := rd
    io.a := a
    io.b := b

}



