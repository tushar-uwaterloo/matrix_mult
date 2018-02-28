module mat_vect_mult1
  # (parameter N = 2,
               DW = 8)
    (aclk,
     areset,
     inp_vect,
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
input [DW-1:0]                       inp_vect [0:N-1];
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
reg                            s_axis_tready_d;
wire                           s_axis_tready_edge;

//s_axis_tready
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    s_axis_tready <= 'b0;
  end else begin
    s_axis_tready <= ~m_axis_tvalid && s_axis_tvalid && ~s_axis_tlast;
  end
end

//m_axis_tdata
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    m_axis_tdata <= 'b0;
  end else begin
    if (s_axis_tvalid && s_axis_tready && s_axis_tready_edge) begin
      m_axis_tdata <= (s_axis_tdata * inp_vect[slice]);
    end else if (s_axis_tvalid && s_axis_tready) begin
      m_axis_tdata <= m_axis_tdata + (s_axis_tdata * inp_vect[slice]);
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
    if (m_axis_tready) m_axis_tvalid <= 'b0;
    else if (s_axis_tlast) m_axis_tvalid <= 'b1;
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
    else if (s_axis_tlast && count == N-1) m_axis_tlast <= 'b1;
  end
end

//count 
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    count <= 'b0;
  end else begin
    if (s_axis_tlast) begin
      if (count == N-1) count <= 'b0;
      else              count <= count + 'b1;
    end
  end
end

//ready edge detection
always@(posedge aclk or posedge areset)
begin
  if (areset) begin
    s_axis_tready_d <= 'b0;
  end else begin
    s_axis_tready_d <= s_axis_tready;
  end
end
assign s_axis_tready_edge = s_axis_tready && ~s_axis_tready_d;



endmodule
       
