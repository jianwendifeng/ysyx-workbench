package rv64

import chisel3._
import chisel3.util._

class IDUIO(Xlen: Int) extends Bundle{
    val inst = Input(UInt(32.W))

    val alu_op = Output(UInt(7.W))
    val rd = Output(UInt(5.W))
    val alu_fun3 = Output(UInt(3.W))
    //val immR = Output(UInt(7.W))
    val data1 = Output(UInt(Xlen.W))
    val data2 = Output(UInt(Xlen.W))
}

class IDU(Xlen: Int) extends Module{
    val io = IO(new IDUIO(Xlen))

    val op = io.inst(6,0)
    val rd = io.inst(11,7)
    val src1 = io.inst(19,15)
    val src2 = io.inst(24,20)
    val funct3 = io.inst(14,12)
    //val immR = io.inst(31,25)
    val ren = RegInit(false.B)
    val wen = RegInit(true.B)

    val data1 = RegInit(0.U(Xlen.W))
    val data2 = RegInit(0.U(Xlen.W))

    ren := Mux(op === "b0110011".U,true.B, false.B)

    val regFileInst = Module(new rv64.RegFile(Xlen))
    
    regFileInst.io.raddr1 := src1
    regFileInst.io.raddr2 := src2
    data1 := regFileInst.io.rdata1
    data2 := regFileInst.io.rdata2
    regFileInst.io.ren := ren
    regFileInst.io.wen := wen
    regFileInst.io.waddr := rd
    regFileInst.io.wdata := 0.U

    io.alu_op := op
    io.rd := rd
    io.alu_fun3 := funct3
    io.data1 := data1
    io.data2 := data2

}



