package rv64.ifu

import chisel3._

class ImemIO extends Bundle {
    val ren = Input(Bool())
    val raddr = Input(UInt(32.W))
    val rdata = Output(UInt(64.W))
}

class Memory extends Module {
    val io = IO(new Bundle{
        val imen = new ImemIO()
    })

    val Imem = Mem(4096, UInt(64.W))
    
    

      // 读取存储器数据
    when(io.ren) {
        io.rdata := Imem.read(io.raddr)
    }
}