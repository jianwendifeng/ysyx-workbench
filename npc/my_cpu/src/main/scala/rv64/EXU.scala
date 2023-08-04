package rv64

import chisel3._
import chisel3.util._

class EXU(Xlen: Int) extends Module {
    val io = IO(new EXUIO(Xlen))
    val ctr_signals = RegNext(io.ctr_signals_in)
    io.ctr_signals_out <> ctr_signals
    
    val result = RegInit(0.U(Xlen.W))
    val rd = RegInit(0.U(5.W))

    val alu = Module(new ALU(Xlen))
    
    alu.io.ctr_signals_in <> io.ctr_signals_in

    alu.io.a <> io.a
    alu.io.b <> io.b
    alu.io.result <> result


    rd := io.rd_in
    io.rd_out := rd
    io.data := result
}