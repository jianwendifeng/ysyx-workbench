package rv64

import chisel3._
import chisel3.stage.ChiselStage

class Core extends Module {
    val io = IO(new Bundle {
        val inst = Input(UInt(32.W))
        val pc = Output(UInt(32.W))
        val exit = Output(UInt(32.W))
        val idu_op = Output(UInt(7.W))
    })

    //ifu 部分
    val ifu = Module(new IFU(32))
    val idu = Module(new IDU(32))
    // val exu = Module(new EXU(32))

    ifu.io.inst <> idu.io.inst
    // ifu.io.

    val pc_reg = RegInit(0.U)
    pc_reg := pc_reg + 4.U(32.W)    
    ifu.io.pc_in := pc_reg  //ifu的pc输入



    //这里代替了imem的功能，写入指令部分
    ifu.io.inst_in := io.inst

 
    //检查端口
    io.pc := pc_reg
    io.exit := ifu.io.inst
    io.idu_op := idu.io.alu_op
}

object fetch_core_Generator extends App{
    (new ChiselStage).emitVerilog(new Core(), args)
}