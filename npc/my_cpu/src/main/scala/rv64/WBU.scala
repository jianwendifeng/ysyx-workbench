package rv64

import chisel3._
import chisel3.util._



class WBU(Xlen: Int) extends Module {
    val io = IO(new WBUIO(Xlen))

    io.wen := io.ctr_signals_in.wb_en
    io.waddr_out  := io.waddr_in
    io.wdata_out  := io.wdata_in
    // val rd = RegInit(0.U(5.W))
    // val data = RegInit(0.U(Xlen.W))
    // val en = RegInit(false.B)

    // val regFileInst = Module(new rv64.RegFile(Xlen))
    
    // en :=  Mux(io.rd.orR, true.B , false.B) 
    // data := io.data
    // data := Mux(io.wen, io.data | 0.U, 0.U)
    // // rd := io.rd
    // rd := Mux(en,io.rd | 0.U,0.U)
    
    // regFileInst.io.waddr := rd
    // regFileInst.io.wdata := data
    // regFileInst.io.wen := io.wen

    // regFileInst.io.raddr1 := DontCare
    // regFileInst.io.raddr2 := DontCare
    // regFileInst.io.rdata1 := DontCare
    // regFileInst.io.rdata2 := DontCare
    // regFileInst.io.ren := DontCare
}