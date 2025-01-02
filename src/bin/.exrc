nnoremap <leader>l <Cmd>40vs std.in<CR>

if has('nvim')
    nnoremap <leader>b <Cmd>wa<CR><Cmd>split<CR><Cmd>term bash ./build.sh %<CR>i
else
    nnoremap <leader>b <Cmd>wa<CR><Cmd>split<CR><Cmd>term ++curwin bash ./build.sh %<CR>
endif
