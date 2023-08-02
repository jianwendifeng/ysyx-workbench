package rv64

import chisel3._
import chisel3.util._

class MEMIO(Xlen: Int) extends Bundle {
    val wen_in = Input(Bool())
    val ren_in = Input(Bool())
    val rd_in = Input(UInt(5.W))
    val result_in = Input(UInt(Xlen.W))


    val wen_out = Output(Bool())
    val rd_out = Output(UInt(5.W))
    val result_out = Output(UInt(Xlen.W))
}

class MEM(Xlen: Int) extends Module {
    val io = IO(new MEMIO(Xlen))

    val result = RegInit(0.U(Xlen.W))
    val rd = RegInit(false.B)
    val wen = RegInit(false.B)

    rd := io.rd_in
    wen := io.wen_in
    io.rd_out := rd
    io.wen_out := wen

    result := io.result_in
    io.result_out := result
}