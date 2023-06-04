// 触发器模板
module Reg #(WIDTH = 1, RESET_VAL = 0) (
  input clk,
  input rst,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk) begin
    if (rst) dout <= RESET_VAL;
    else if (wen) dout <= din ;	
  end
endmodule


module pc(
  input clk,
  input rst,
  input [63:0] pc_in,
  output [63:0] pc_out
);
  // 位宽为32比特, 复位值为32'h80000000 (0x80000000), 写使能一直有效
  Reg #(32, 32'h80000000) i0 (clk, rst, in[63:0], out[63:0], 1'b1);
endmodule
