package rv64

import chisel3._

class WBIO(xlen: Int) extends Bundle {
        val wb_addr = Input(UInt(32.W))
        val wb_data = Input(UInt(64.W))
}

class WB(xlen: Int) extends  Bundle {
    val io = IO(new WBIO(xlen))
    val addr = RegInit(0.U(5.W))
    val data = RegInit(0.U(64.W))
    val en = RegInit(Bool())

    val regFileInst = Module(new rv64.RegFile(xlen))
    
    en =  Mux(io.raddr.orR, true , false) 
    data := io.wb_data
    addr := io.wb_addr
    
    regFileInst.io.waddr := addr
    regFileInst.io.wdata := data
    regFileInst.io.wen := en
}