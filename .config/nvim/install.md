# Install Neovim with all the Plugins

- install packer (the plugin manager)
- create a neovim config directory
- copy all of the files except for `install.md` to the newly created directory
- open nvim and run the `PackerSync` command

```bash
git clone --depth 1 https://github.com/wbthomason/packer.nvim\
 ~/.local/share/nvim/site/pack/packer/start/packer.nvim
mkdir -p ~/.config/nvim
cp -r ./init.lua ./lua ./plugin -t ~/.config/nvim
(inside nvim):PackerSync
```
