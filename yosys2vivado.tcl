# vivado -mode tcl -s yosys2vivado.tcl
read_edif mat_vect_mult2.edif
read_xdc mat_vect_mult2.xdc
link_design \
	-part xc7z020clg400-1 \
	-top mat_vect_mult2 \
	-mode out_of_context
opt_design; 
place_design; 
route_design
report_utilization; 
report_timing; 
report_power;
exit
