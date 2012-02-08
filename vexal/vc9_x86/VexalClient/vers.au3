$fl = FileOpen("vversion.hpp", 0)
$spl = StringSplit(FileRead($fl), ".")
$np = stringinstr($spl[4], '"')
$nn = StringLeft($spl[4], $np - 1)
$nn = int($nn) + 1
$ne = StringMid($spl[4], $np)
$ns = $spl[1] & "." & $spl[2] & "." & $spl[3] & "." & $nn & $ne
FileClose($fl)
$fl = FileOpen("vversion.hpp", 2)
FileWrite($fl, $ns)
FileClose($fl)