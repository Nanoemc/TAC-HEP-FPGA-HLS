open_project pragma_arraycompleteunrolldataflow
set_top lec8Ex1
add_files lec8Ex1.c
add_files -tb lec8Ex1_tb.c
add_files -tb lec8Ex1_out_ref.dat
 
open_solution "solution1"
set_part  {xc7k160tfbg484-2}
create_clock -period 10
  
#source "./lec8Ex1/solution1/directives.tcl"
   
csim_design
csynth_design
#cosim_design
#export_design -format ip_catalog

# Exit Vivado HLS
exit
