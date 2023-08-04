package rv64

import chisel3._
import chisel3.util._

class MEM(Xlen: Int) extends Module {
    val io = IO(new MEMIO(Xlen))
    val ctr_signals = RegNext(io.ctr_signals_in)
    io.ctr_signals_out := ctr_signals

    val result = RegInit(0.U(Xlen.W))
    val rd = RegInit(false.B)
    // val wen = RegInit(false.B)

    rd := io.rd_in
    // wen := io.ctr_signals_in.wb_en

    io.rd_out := rd
    // io.wen_out := wen

    result := io.result_in
    io.result_out := result
}