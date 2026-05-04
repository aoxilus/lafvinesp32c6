# check-esp32.ps1 - Detection script for UeeKKoo ESP32-C6-1.47" board
# Run this after putting board in bootloader mode (BOOT + RESET)

Write-Host "=== ESP32-C6 WiFi Analyzer Device Detector ===" -ForegroundColor Cyan
Write-Host "Board: UeeKKoo ESP32-C6-1.47 LCD (Amazon B0DHVQYFGM)`n" -ForegroundColor Yellow

function Get-ESP32Devices {
    Write-Host "`n[1] Checking Serial Ports (COM ports):" -ForegroundColor Green
    $ports = Get-WmiObject Win32_SerialPort | Select-Object Name, DeviceID, Description
    if ($ports) {
        $ports | Format-Table -AutoSize
    } else {
        Write-Host "   No traditional COM ports found." -ForegroundColor Gray
    }

    Write-Host "`n[2] Checking USB Devices for ESP32-C6 (VID 303A or bootloader):" -ForegroundColor Green
    $usbDevices = Get-PnpDevice | Where-Object { 
        $_.InstanceId -like "*VID_303A*" -or 
        $_.InstanceId -like "*ESP*" -or 
        $_.FriendlyName -like "*ESP*" -or 
        $_.FriendlyName -like "*Serial*" -or
        $_.InstanceId -like "*USB\VID_0000*"
    } | Select-Object FriendlyName, InstanceId, Status
    
    if ($usbDevices) {
        $usbDevices | Format-Table -AutoSize -Wrap
    } else {
        Write-Host "   No ESP32-related USB devices detected yet." -ForegroundColor Gray
    }

    Write-Host "`n[3] All USB Composite Devices (looking for new ones):" -ForegroundColor Green
    Get-PnpDevice -Class USB | Where-Object { 
        $_.FriendlyName -like "*Composite*" -or $_.FriendlyName -like "*Serial*" 
    } | Select-Object FriendlyName, InstanceId | Format-Table -AutoSize -Wrap

    Write-Host "`n`nTip: Look for a new COM port (like COM5, COM6, COM16, etc.) or 'USB Serial Device'." -ForegroundColor Cyan
    Write-Host "If you see a new port, note the number (e.g. COM5) and tell me." -ForegroundColor White
}

# Run detection
Get-ESP32Devices

Write-Host "`n`nTo run this again: .\check-esp32.ps1" -ForegroundColor Gray
Write-Host "Keep running this script while you try different BOOT+RESET combinations." -ForegroundColor Gray
