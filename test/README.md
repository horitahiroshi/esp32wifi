## Testing BT comm between Ubuntu and ESP32

For testing BT communication between Ubuntu 10.04 and ESP32, follow steps:

1. Find the ESP32 Bluetooth identification
```
hcitool scan
```
It must return something like this:
```
3C:71:BF:42:34:16   ESP32BT
```
2. Connect the ESP32BT
```
sudo rfcomm connect /dev/rfcomm0 3C:71:BF:42:34:16 1 &
```
If necessary, clean up all BT connections before with the command:
```
sudo killall rfcomm
```
3. Initiate the Serial BT communication
```
sudo screen /dev/rfcomm0
```