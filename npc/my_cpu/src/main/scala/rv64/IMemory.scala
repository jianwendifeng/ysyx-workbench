package rv64

import chisel3._
import chisel3.util._
import chisel3.stage._
import chisel3.util.experimental.loadMemoryFromFile
import firrtl.annotations.MemoryLoadFileType
import scala.io.Source

class ImemIO extends Bundle {
    val addr = Input(UInt(32.W))
    val inst = Output(UInt(32.W))
}

class IMemory extends Module {
    val io = IO(new Bundle{
        val imem = new ImemIO()
    })

    val mem = Mem(64, UInt(32.W)) //2^14  16384/4=4096,最多4096条指令
     //loadMemoryFromFile(mem, "mem.hex")  //读取指令
    io.imem.inst := mem(io.imem.addr)
}

// object fetch_inst extends App{
//     (new ChiselStage).emitVerilog(new IMemory(),args)
// }