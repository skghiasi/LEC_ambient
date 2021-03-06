# THIS FILE IS AUTOMATICALLY GENERATED
# Project: F:\Psoc project\Hadi\Workspace01\Design01.cydsn\Design01.cyprj
# Date: Mon, 18 Jun 2018 12:52:21 GMT
#set_units -time ns
create_clock -name {ADC_SAR_SEQ_intClock(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {UART_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {I2CM_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {Clk_Timer_1(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {Clk_Timer(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_SAR_SEQ_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {I2CM_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]
create_generated_clock -name {Clk_Timer_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]
create_generated_clock -name {Clk_Timer} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for F:\Psoc project\Hadi\Workspace01\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: F:\Psoc project\Hadi\Workspace01\Design01.cydsn\Design01.cyprj
# Date: Mon, 18 Jun 2018 12:52:19 GMT
