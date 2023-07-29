package rv64

import chisel3._
import chisel3.util._

class DecoderIO extends Bundle{
    val io = IO(new Bundle{
        val inst = Input(UInt(32.W))
        val alu_op = Output(UInt(7.W))
        val rd = Output(UInt(5.W))
        val alu_fun3 = Output(UInt(3.W))
        val immR = Output(UInt(7.W))
        val data1 = Output(UInt(64.W))
        val data2 = Output(UInt(64.W))
    })
}




class Decoder(xlen: Int) extends Module{
    val io = IO(new DecoderIO)

    val inst_op = io.inst(6,0)
    val inst_rd = io.inst(11,7)
    val src1 = io.inst(19:15)
    val src2 = io.inst(24,20)
    val funct3 = io.inst(14:12)
    val immR = io.inst(31:25)
    val ren = RegInit(false.B)
    val wen = RegInit(true.B)

    val data1 = RegInit(0.U(64.W))
    val data2 = RegInit(0.U(64.W))
    val fun3 =  RegInit(0.U(3.W))
    val op = RegInit(0.U(7.W))
    val immr = RegInit(0.U(7.W))
    val rd = RegInit(0.U(5.W))

    op = inst_op
    fun3 := funct3
    rd := inst_rd
    
    io.alu_fun3 := fun3
    io.alu_op = op
    io.rd = rd
    io.immR = immr

    when(inst_op === 0110011){
        ren := true
    } .otherwise{
        ren := false
    }

    val regFileInst = Module(new rv64.RegFile(xlen))
    
    regFileInst.io.raddr1 := src1
    regFileInst.io.raddr2 := src2
    data1 := regFileInst.io.rdata1
    data2 := regFileInst.io.rdata2
    regFileInst.io.ren := ren
    regFileInst.io.wen := wen
    regFileInst.io.waddr := DontCare
    regFileInst.io.wdata := Dontcare

    io.data1 := data1
    io.data2 := data2

}



