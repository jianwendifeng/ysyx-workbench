module Reg #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input  [ADDR_WIDTH-1:0] raddr,
  output reg [DATA_WIDTH-1:0] rdata
);
  
	reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

    // 初始化
  initial begin
    rf[0] = 32'b0;  // 寄存器0不进行初始化
    for (integer i = 0; i < 2**ADDR_WIDTH; i = i + 1) begin
      rf[i] = i;
    end
  end
  
	always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  assign rdata = rf[raddr];

endmodule
