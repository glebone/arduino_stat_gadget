use strict;
use warnings;
use Device::SerialPort;
use POSIX;


my $port = Device::SerialPort->new("/dev/ttyACM1");
$port->databits(8);
$port->baudrate(9600);
$port->parity("none");
$port->stopbits(1);



open(INFIL,"< /proc/stat") or die("Unable To Open /proc/stat: $!\n");
while()
{
   my @loads;
   my $cpuload = 0;
   for (0,1)
   {
      my $in = <INFIL>;
      (warn "something wrong!\n"), next unless $in =~ /^cpu\b/;
      push @loads,  ($in =~ /\d+/g)[0..2];
      seek INFIL, 0, 0;
      select (undef, undef, undef, 1) unless $_;
   }
   redo unless defined $loads[0];
   for (0..2) { $cpuload += ($loads[$_+3] - $loads[$_]); }
   
	$cpuload = $cpuload/3;
	$cpuload = ceil($cpuload);
	if(length($cpuload) == 1){
		$cpuload = "00".$cpuload;	
	}
	if(length($cpuload) == 2){
		$cpuload = "0".$cpuload;	
	}
	print "$cpuload \n";
	my $random_integer = int(rand(10)) + 1;

   print "<p>Your Acme Auto Lucky Integer from 1 to 10 is $random_integer.</p>\n"; 
   $port->write($cpuload.$cpuload);
}
close(INFIL);





