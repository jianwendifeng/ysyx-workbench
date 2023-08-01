// package rv64

// import chisel3._
// import chisel3.util._

// class EXUIO(xlen: Int) extends Bundle {
//     val op = Input(UInt(7.W))
//     val rd_in =Input(UInt(5.W))
//     val fun3 = Input(UInt(3.W))
//     //val immR = Input(UInt(7.W))
//     val data1 = Input(UInt(xlen.W))
//     val data2 = Input(UInt(xlen.W))

//     val wen = Output(Bool())
//     val ren = Output(Bool())
//     val rd_out = Output(UInt(5.W))
//     val data = Output(UInt(xlen.W))
// }


// class EXU(xlen: Int) extends Module {
//     val io = IO(new EXUIO(xlen))
//     val result = RegInit(0.U(xlen.W))
//     val rd = RegInit(0.U(5.W))
//     //val alu = 
//     rd := io.rd_in

//     result := MuxCase(0.U, Array(
//         ((io.op === "b0110011".U) && (io.fun3 === "b000".U)) -> io.data1 + io.data2
//     ))
//     io.wen := result =/= false
//     io.ren := false
//     io.rd := rd
//     io.data := result
// }