module mat_vect_mult2
  # (parameter N = 2,
               DW = 8)
    (aclk,
     areset,
     inp_vect,
     inp_vect_valid,
     inp_vect_rdy,
     s_axis_tdata,
     s_axis_tvalid,
     s_axis_tlast,
     s_axis_tready,
     m_axis_tdata,
     m_axis_tvalid,
     m_axis_tlast,
     m_axis_tready
    );

input                                aclk;
input                                areset;
input [DW-1:0]                       inp_vect;
input                                inp_vect_valid;
output wire                          inp_vect_rdy;
input [DW-1:0]                       s_axis_tdata;
input                                s_axis_tvalid;
input                                s_axis_tlast;
output reg                           s_axis_tready;
output reg [(2*DW + $clog2(N))-1:0]  m_axis_tdata;
output reg                           m_axis_tvalid;
output reg                           m_axis_tlast;
input                                m_axis_tready;

reg [$clog2(N)-1:0]            count;
reg [$clog2(N)-1:0]            slice;
wire [DW-1:0]                  inp_vect_lat [0:N-1];
reg [DW-1:0]                   inp_vect_reg [0:N-1];

genvar i;
for (i=0; i<N; i=i+1) begin : lat_loop
  assign inp_vect_lat[i] = (inp_vect_rdy && inp_vect_valid && slice == i) ? inp_vect : inp_vect_reg[i] ; 
  
  always@(posedge aclk or posedge areset)
  begin
    if (areset) begin
      inp_vect_reg[i] <= 'b0;
    end else begin
      inp_vect_reg[i] <= inp_vect_lat[i];
    end
  end
end


 
//s_axis_tready
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    s_axis_tready <= 'b0;
  end else begin
    if (s_axis_tlast || (m_axis_tvalid && ~m_axis_tready))
      s_axis_tready <= 'b0;
    else
      s_axis_tready <= 'b1;
  end
end

assign inp_vect_rdy = (count==0) ? s_axis_tready : 'b0;

//m_axis_tdata
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    m_axis_tdata <= 'b0;
  end else begin
    if (s_axis_tvalid && s_axis_tready) begin
      m_axis_tdata <= m_axis_tdata + (s_axis_tdata * inp_vect_lat[slice]);
    end else if (m_axis_tvalid && m_axis_tready) begin
      m_axis_tdata <= 'b0;
    end 
  end  
end

//slice
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    slice <= 'b0;
  end else begin
    if (s_axis_tvalid && s_axis_tready && s_axis_tlast) begin
      slice <= 'b0;
    end else if (s_axis_tvalid && s_axis_tready) begin
      slice <= slice + 'b1;
    end
  end
end

//m_axis_tvalid
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    m_axis_tvalid <= 'b0;
  end else begin
    if (s_axis_tlast && s_axis_tready) m_axis_tvalid <= 'b1;
    else if (m_axis_tready) m_axis_tvalid <= 'b0;
  end
end

//m_axis_tlast
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    m_axis_tlast <= 'b0;
  end else begin
    if (m_axis_tready) m_axis_tlast <= 'b0;
/* verilator lint_off WIDTH */
    else if (s_axis_tlast && s_axis_tready && count == N-1) m_axis_tlast <= 'b1;
  end
end

//count 
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    count <= 'b0;
  end else begin
    if (s_axis_tlast && s_axis_tready) begin
      if (count != N-1) count <= count + 'b1;
    end
  end
end

endmodule
       
