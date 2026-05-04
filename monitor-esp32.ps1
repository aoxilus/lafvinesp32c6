# monitor-esp32.ps1 - Live monitoring script for ESP32-C6 bootloader mode
# Run this, then put your board into bootloader mode (hold BOOT, press RESET, release BOOT)

Write-Host "=== ESP32-C6 Live Monitor ===" -ForegroundColor Cyan
Write-Host "Waiting for your UeeKKoo ESP32-C6-1.47 board in bootloader mode..." -ForegroundColor Yellow
Write-Host "Instructions: Hold BOOT button → Press & release RESET → Release BOOT`n" -ForegroundColor White

$previousPorts = @()
$run = $true
$counter = 0

while ($run) {
    $counter++
    Clear-Host
    Write-Host "=== ESP32-C6 Monitor (scan #$counter) ===" -ForegroundColor Cyan
    Write-Host "Time: $(Get-Date -Format 'HH:mm:ss')" -ForegroundColor Gray
    Write-Host "Looking for VID_303A (ESP32-C6 native USB) or new COM port...`n"

    # Check Serial Ports
    Write-Host "→ Serial Ports:" -ForegroundColor Green
    $ports = Get-WmiObject Win32_SerialPort | Select-Object Name, DeviceID, Description
    if ($ports) {
        $ports | Format-Table -AutoSize
    } else {
        Write-Host "   None detected" -ForegroundColor Gray
    }

    # Check for ESP32 USB devices specifically
    Write-Host "`n→ USB Devices with ESP32 signatures:" -ForegroundColor Green
    $espDevices = Get-PnpDevice | Where-Object { 
        $_.InstanceId -match "VID_303A|ESP|JTAG|Serial.*Debug" -or 
        $_.FriendlyName -match "ESP|JTAG|Serial.*Debug"
    } | Select-Object FriendlyName, InstanceId, Status, Manufacturer
    
    if ($espDevices) {
        $espDevices | Format-Table -AutoSize
        Write-Host "`nSUCCESS: ESP32 device detected!" -ForegroundColor Green
        Write-Host "Please tell me the COM port number shown above." -ForegroundColor White
        break
    } else {
        Write-Host "   No ESP32 device in bootloader mode detected yet." -ForegroundColor Yellow
    }

    # Show any "Unknown USB Device" as they often represent bootloader
    $unknown = Get-PnpDevice | Where-Object { $_.FriendlyName -like "*Unknown USB Device*" -or $_.InstanceId -like "*VID_0000*" }
    if ($unknown) {
        Write-Host "`n→ Unknown USB Devices (common in bootloader):" -ForegroundColor Magenta
        $unknown | Select-Object FriendlyName, InstanceId | Format-Table -AutoSize
    }

    Write-Host "`nPress Ctrl+C to stop. Keep trying BOOT+RESET while this runs." -ForegroundColor Gray
    Start-Sleep -Seconds 3
}

Write-Host "`nMonitoring stopped." -ForegroundColor Gray
