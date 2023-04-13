open_project lec5Ex2_high_part2
set_top lec5Ex1
add_files lec5Ex1_high.c
add_files -tb lec5Ex1_test_high.c
add_files -tb lec5Ex1_out_high_ref.dat
 
open_solution "bob"
set_part  {xc7k160tfbg484-2}
create_clock -period 10
  
#source "./lec5Ex2_high_part2/bob/directives.tcl"
   
csim_design
csynth_design
cosim_design
#export_design -format ip_catalog

# Exit Vivado HLS
exit
