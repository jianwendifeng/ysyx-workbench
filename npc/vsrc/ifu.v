module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
	output [DATA_WIDRH-1:0] rdata 
);
  reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end
	
	
endmodule

module ifu(
	input	clk,
	input [63:0] if_data,
	input [63:0] if_addr,
	input wen
);

	wire [63:0] id_rdata;
	RegisterFile #(64, 64) i0(clk,if_data,if_addr,wen,id_rdata);
endmodule
