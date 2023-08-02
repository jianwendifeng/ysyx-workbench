package rv64

import chisel3._
import chisel3.util._

class ALUIO(Xlen: Int) extends Bundle {
    val op = Input(UInt(7.W))
    val fun3 = Input(UInt(3.W))
    val data1 = Input(UInt(Xlen.W))
    val data2 = Input(UInt(Xlen.W))
    
    val result = Output(UInt(Xlen.W))
}

class ALU(Xlen: Int) extends Module {
    val io = IO(new ALUIO(Xlen))
    
    when(io.op === "b0110011".U && io.fun3 === "b000".U) {
        io.result := io.data1 + io.data2
    }.otherwise {
        io.result := 0.U
    }

}