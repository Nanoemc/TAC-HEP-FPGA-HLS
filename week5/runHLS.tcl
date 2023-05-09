open_project imperfectloop_flatten
set_top lec9Ex4
add_files lec9Ex4.c
add_files -tb lec9Ex4_tb.c
add_files -tb lec9Ex4_out_ref.dat
 
open_solution "solution1"
set_part  {xc7k160tfbg484-2}
create_clock -period 10
  
#source "./lec9Ex4/solution1/directives.tcl"
   
csim_design
csynth_design
#cosim_design
#export_design -format ip_catalog

# Exit Vivado HLS
exit
