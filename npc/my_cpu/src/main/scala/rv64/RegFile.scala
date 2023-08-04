package rv64

import chisel3._

class RegFile(Xlen: Int) extends Module {
    val io = IO(new RegFileIO(Xlen))
    val regs = Mem(32, UInt(Xlen.W))
    
    for(i <- 0 until 32){
        regs.write(i.U,i.U)
    }
    
    io.rdata1 :=  Mux(io.raddr1.orR && io.ren, regs(io.raddr1), 0.U)  //任意一位为1,io.raddr1.orR为true
    io.rdata2 :=  Mux(io.raddr2.orR && io.ren, regs(io.raddr2), 0.U)
    regs(io.waddr) := Mux(io.wen & io.waddr.orR , io.wdata ,0.U)
}
