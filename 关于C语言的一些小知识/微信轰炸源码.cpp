Set WshShell = WScript.CreateObject("WScript.Shell")
WshShell.AppActivate"Ìï"
for i = 1 to 100
WScript.Sleep 100
WshShell.Sendkeys"^v"
WshShell.Sendkeys i
WshShell.Sendkeys "%s"
Next