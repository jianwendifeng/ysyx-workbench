// package rv64

// import chisel3._

// class WBIO(xlen: Int) extends Bundle {
//         val addr = Input(UInt(32.W))
//         val data = Input(UInt(xlen.W))
//         val wen = Input(Bool())
// }

// class WB(xlen: Int) extends  Bundle {
//     val io = IO(new WBIO(xlen))
//     val addr = RegInit(0.U(5.W))
//     val data = RegInit(0.U(xlen.W))
//     val en = RegInit(Bool())

//     val regFileInst = Module(new rv64.RegFile(xlen.W))
    
//     en =  Mux(io.raddr.orR, true , false) 
//     data := io.wb_data
//     addr := io.wb_addr
    
//     regFileInst.io.waddr := addr
//     regFileInst.io.wdata := data
//     regFileInst.io.wen := en
// }