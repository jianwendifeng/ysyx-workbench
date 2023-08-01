package rv64

import chisel3._

class RegFileIO(xlen: Int) extends Bundle {
    val raddr1 = Input(UInt(5.W))
    val raddr2 = Input(UInt(5.W))
    val rdata1 = Output(UInt(xlen.W))
    val rdata2 = Output(UInt(xlen.W))
    val ren = Input(Bool())
    val wen = Input(Bool())
    val waddr = Input(UInt(5.W))
    val wdata = Input(UInt(xlen.W))
}

class RegFile(xlen: Int) extends Module {
    val io = IO(new RegFileIO(xlen))
    val regs = Mem(32, UInt(xlen.W))
    
    io.rdata1 :=  Mux(io.raddr1.orR && io.ren, regs(io.raddr1), 0.U)  //任意一位为1,io.raddr1.orR为true
    io.rdata2 :=  Mux(io.raddr2.orR && io.ren, regs(io.raddr2), 0.U)
    regs(io.waddr) := Mux(io.wen & io.waddr.orR , io.wdata ,0.U)
}