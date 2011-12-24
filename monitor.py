import psutil
import serial

arduino = serial.Serial('/dev/ttyACM1', 9600)  

while 1:
  cpu =  str(round(psutil.cpu_percent(interval=1))).rstrip('0').rstrip('.')
  cpu_tot = '0' + str(cpu)
  if (len(cpu_tot) < 3):
	  cpu_tot = '0' + cpu_tot
  mem = psutil.phymem_usage()
  mem_tot = '0' + str(round(mem.percent)).rstrip('0').rstrip('.')
  if (len(mem_tot) < 3):
	  mem_tot = '0' + mem_tot
  try:  
      arduino.write(cpu_tot+mem_tot)
  except:
	  print "Failed to send!"      	  
  
