#!/usr/bin/env sh
xset -dpms
xset s off
xset s noblank

unclutter &
chromium-browser 192.168.1.77/app/blinky.html \
  --start-fullscreen \
  --kiosk \
  --noerrdialogs \
  --fast \
  --fast-start \
  --disable-infobars 
