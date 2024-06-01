set tabstop=2                 " n columns per tab
set shiftwidth=2              " n columns to indent with << and >>
set expandtab                 " insert spaces for tabs
set listchars=tab:··,trail:⎵  ""show tab and trailing whitespace

"
"" run rubocoap on current file
map <leader>r :exec '!clear && make run'<CR>
map <leader>f :exec '!clear && make fmt'<CR>
map <leader>t :exec '!clear && make test'<CR>
map <leader>l :bufdo e!
