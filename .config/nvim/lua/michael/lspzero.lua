local lsp = require('lsp-zero')
lsp.preset('recommended')

lsp.ensure_installed({
    'rust_analyzer',
    'sumneko_lua',
    'clangd',
})

lsp.nvim_workspace()
lsp.setup()
