set tabstop=2                 "" n columns per tab
set shiftwidth=2              "" n columns to indent with << and >>
set expandtab                 "" insert spaces for tabs
set listchars=tab:··,trail:⎵  "" show tab and trailing whitespace

"" run rubocoap on current file
map <leader>m :exec '!clear && make debug extras'<CR>
map <leader>t :exec '!clear && make test'<CR>
map <leader>r :exec '!clear && make run'<CR>
map <leader>f :exec '!clear && make fmt'<CR>
map <leader>c :exec '!clear && make clean'<CR>
map <leader>d :exec '!clear && make gdb'<CR>
map <leader>u :exec '!clear && make ctags'<CR>
