module pc #(RESET_VAL = 32'h80000000) (
  input clk,
  input rst,
  output reg [31:0] pc_out
);

	always @ (posedge clk) begin
		if(rst) pc_out <= RESET_VAL;
		else pc_out <= pc_out + 4;
	end

endmodule
