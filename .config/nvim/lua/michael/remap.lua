function Map(mode, lhs, rhs, opts)
    local options = { noremap = true }
    if opts then
        options = vim.tbl_extend("force", options, opts)
    end
    vim.api.nvim_set_keymap(mode, lhs, rhs, options)
end

vim.g.mapleader = " "
Map("n", "<leader>.",  ":NvimTreeToggle<CR>", {silent=true})
Map("n", "<leader>n",  ":tabnext<CR>", {silent=true})
Map("n", "<leader>p",  ":tabprevious<CR>", {silent=true})
Map("n", "<leader>tn", ":tabnew<CR>", {silent=true})
Map("n", "<leader>ff", ":Telescope find_files<CR>", {silent=true})
Map("n", "<leader>qq", ":wq<CR>", {silent=true})
