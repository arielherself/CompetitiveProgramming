vim.api.nvim_create_autocmd("FileType", {
    pattern = "cpp",
    callback = function()
        vim.api.nvim_buf_set_keymap(0, 'n', "<leader>b", '<Cmd>10sp<CR><Cmd>te ctext -i $(gcc -xc++ /dev/null -E -Wp,-v 2>&1 | sed -n "s,^ ,,p" | tr "\\n" ",") < % > ctext_out.cc && clang++ -std=c++17 -DONLINE_JUDGE -Wl,-z,stack-size=268435456 -Wall -Ofast -g -fsanitize=address -fsanitize=undefined ctext_out.cc && ./a.out < std.in<CR>i', {
            silent = true,
            noremap = true
        })
    end,
})

vim.api.nvim_create_autocmd("FileType", {
    pattern = "python",
    callback = function()
        vim.api.nvim_buf_set_keymap(0, 'n', "<leader>b", "<Cmd>10sp<CR><Cmd>te python3 %<CR>i", {
            silent = true,
            noremap = true
        })
    end,
})

vim.keymap.set('n', '<leader>y', '<Cmd>!ctext -i $(gcc -xc++ /dev/null -E -Wp,-v 2>&1 | sed -n "s,^ ,,p" | tr "\\n" ",") < % > ctext_out.cc<CR><Cmd>split ctext_out.cc<CR>:%%y+<CR><Cmd>q<CR>')
vim.keymap.set('n', '<leader>1', '<Cmd>CphReceive<CR>');
vim.keymap.set('n', '<leader>2', '<Cmd>CphTest<CR>');
vim.keymap.set('n', '<leader>3', '<Cmd>r ~/RustIsBestLang/src/bin/template.cc<CR>G');
vim.keymap.set('n', '<leader>l', '<Cmd>40vs std.in<CR>')
