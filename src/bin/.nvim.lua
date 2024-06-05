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

local function add_timestamp()
    local bufnr = vim.api.nvim_get_current_buf()
    if vim.fs.basename(vim.api.nvim_buf_get_name(bufnr)) == "template.cc" then
        return
    end
    local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)

    local current_time = os.time()
    local current_time_str = os.date("%Y-%m-%d %H:%M:%S", current_time)

    local create_time_str = ""
    local elapsed_minutes = 0
    if #lines > 0 and lines[1]:match("/**") then
        create_time_str = lines[3]:match(" * Created:  (.*)")
        local create_time = os.time({
            year = tonumber(create_time_str:sub(1, 4)),
            month = tonumber(create_time_str:sub(6, 7)),
            day = tonumber(create_time_str:sub(9, 10)),
            hour = tonumber(create_time_str:sub(12, 13)),
            min = tonumber(create_time_str:sub(15, 16)),
            sec = tonumber(create_time_str:sub(18, 19)),
        })
        elapsed_minutes = math.floor((current_time - create_time) / 60)
    else
        create_time_str = current_time_str
    end

    local comment_string = {
        "/**",
        " * Author:   subcrip",
        " * Created:  " .. create_time_str,
        " * Modified: " .. current_time_str,
        " * Elapsed:  " .. elapsed_minutes .. " minutes",
        " */",
        "",
    }

    if #lines > 0 and lines[1]:match("/**") then
        for i = 1, #comment_string do
            lines[i] = comment_string[i]
        end
    else
        for i = #comment_string, 1, -1 do
            table.insert(lines, 1, comment_string[i])
        end
    end

    vim.cmd("undojoin")
    vim.api.nvim_buf_set_lines(bufnr, 0, -1, false, lines)
end

-- vim.api.nvim_create_autocmd(
--     "BufWritePre",
--     {
--         pattern = "*.cc",
--         callback = add_timestamp,
--     }
-- )
