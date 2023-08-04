package rv64

import chisel3._
import chisel3.stage.ChiselStage

class Core extends Module {
    val io = IO(new Bundle {
        val inst = Input(UInt(32.W))
        val pc = Output(UInt(32.W))
        val exit = Output(UInt(32.W))
        val idu_op = Output(UInt(7.W))
        val exu_data = Output(UInt(32.W))
        val exu_data1 = Output(UInt(32.W))
        val exu_data2 = Output(UInt(32.W))
        val mem_data = Output(UInt(32.W))
        val wbu_data = Output(UInt(32.W))
    })

    //ifu 部分
    val ifu = Module(new IFU(32))
    val idu = Module(new IDU(32))
    val exu = Module(new EXU(32))
    val mem = Module(new MEM(32))
    val wbu = Module(new WBU(32))

    ifu.io.inst <> idu.io.inst
    idu.io.alu_sel <> exu.io.alu_sel
    idu.io.rd <> exu.io.rd_in
    // idu.io.alu_fun3 <> exu.io.fun3
    //idu.io.immR = exu.io.immR
    idu.io.a <> exu.io.a
    idu.io.b <> exu.io.b

    exu.io.wen <> mem.io.wen_in
    exu.io.ren <> mem.io.ren_in
    exu.io.rd_out <> mem.io.rd_in
    exu.io.data <> mem.io.result_in

    mem.io.wen_out <> wbu.io.wen
    mem.io.rd_out <> wbu.io.rd
    mem.io.result_out <> wbu.io.data


    val pc_reg = RegInit(0.U)
    pc_reg := pc_reg + 4.U(32.W)    
    ifu.io.pc_in := pc_reg  //ifu的pc输入



    //这里代替了imem的功能，写入指令部分
    ifu.io.inst_in := io.inst

 
    //检查端口
    io.pc := pc_reg
    io.exit := ifu.io.inst
    io.idu_op := idu.io.alu_sel
    io.exu_data := exu.io.data
    io.exu_data1 := exu.io.a
    io.exu_data2 := exu.io.b
    io.mem_data := mem.io.result_out
    io.wbu_data := wbu.io.data
}

object fetch_core_Generator extends App{
    (new ChiselStage).emitVerilog(new Core(), args)
}