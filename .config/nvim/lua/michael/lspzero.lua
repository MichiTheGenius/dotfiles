local lsp = require('lsp-zero')
lsp.preset('recommended')

lsp.ensure_installed({
    'rust_analyzer',
    'sumneko_lua',
})

lsp.nvim_workspace()
lsp.setup()
