# Enable dark mode on linux version of chromium

> Go to the `/usr/share/applications` directory
>
> Open the `chromium.desktop file` and change the existing `Exec` line to this one:
>

```bash
Exec=/usr/bin/chromium --enable-features=WebUIDarkMode --force-dark-mode %U
```
