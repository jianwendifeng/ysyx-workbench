module pc #(RESET_VAL = 0x80000000) (
  input clk,
  input rst,
  //input [63:0] pc_in,
  output [63:0] pc_out
);

	always @ (posedge clk) begin
		if(rst) pc_out <= RESET_VAL;
		else if pc_out <= pc_out + 4;
	end

endmodule
