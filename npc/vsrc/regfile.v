module Reg #(ADDR_WIDTH = 32, DATA_WIDTH = 32) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
	input reg [31:0] raddr,
  output reg [31:0] rdata
);
  
	reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  
	always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  always @(posedge clk) begin
    rdata <= rf[waddr];
  end

endmodule
