package rv64

import chisel3._
import chisel3.util._

class EXUIO(Xlen: Int) extends Bundle {
    val op = Input(UInt(7.W))
    val rd_in =Input(UInt(5.W))
    val fun3 = Input(UInt(3.W))
    //val immR = Input(UInt(7.W))
    val data1 = Input(UInt(Xlen.W))
    val data2 = Input(UInt(Xlen.W))

    val wen = Output(Bool())
    val ren = Output(Bool())
    val rd_out = Output(UInt(5.W))
    val data = Output(UInt(Xlen.W))
}


class EXU(Xlen: Int) extends Module {
    val io = IO(new EXUIO(Xlen))
    val result = RegInit(0.U(Xlen.W))
    val rd = RegInit(0.U(5.W))
    val alu = Module(new ALU(Xlen))
    
    alu.io.op <> io.op
    alu.io.data1 <> io.data1
    alu.io.data2 <> io.data2
    alu.io.fun3 <> io.fun3
    alu.io.result <> result
    

    // result := MuxCase(0.U, Array(
    //     ((io.op === "b0110011".U) && (io.fun3 === "b000".U)) -> io.data1 + io.data2
    // ))
    // when(io.op === "b0110011".U && io.fun3 === "b000".U) {
    //     result := io.data1 + io.data2
    // }.otherwise {
    //     result := 0.U
    // }

    rd := io.rd_in
    io.wen := result =/= false.B
    io.ren := false.B
    io.rd_out := rd
    io.data := result
}