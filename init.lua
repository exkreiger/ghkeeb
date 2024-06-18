vim.g.startify_custom_header =  {
[[]],
[[]],
[[EXK.EXE]],
[[]],
[[]],
[[]],
[[]],
} 


-- Basic settings 
vim.o.swapfile = false
vim.o.awa = true --autowrite on
vim.o.number = true -- Enable line numbers 
vim.o.relativenumber = true -- Enable relative line numbers 
vim.o.tabstop = 4 -- Number of spaces a tab represents 
vim.o.shiftwidth = 4 -- Number of spaces for each indentation 
vim.o.expandtab = true -- Convert tabs to spaces 
vim.o.smartindent = true -- Automatically indent new lines 
vim.o.splitbelow = true
vim.o.wrap = false -- Disable line wrapping 
vim.o.termguicolors = true -- Enable 24-bit RGB colors  
vim.opt.whichwrap = '<,>,[,],b,s'  -- Syntax highlighting and filetype plugins 
vim.o.mouse = 'a' --mouse enabled 
vim.o.clipboard = 'unnamedplus'
vim.o.selection = 'exclusive'
vim.o.selectmode = 'mouse,key'
vim.o.keymodel = 'startsel,stopsel'
vim.o.splitbelow = true

vim.o.colorcolumn = '80'
vim.cmd('syntax enable') 
vim.cmd('filetype plugin indent on')  
vim.cmd('highlight ColorColumn ctermbg=LightCyan')

-- Leader key 
vim.g.mapleader = ' ' -- Space as the leader key 

-- Remaps
vim.api.nvim_set_keymap('n', '<Leader>z', ':noh<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('t', '<Esc>', "<C-\\><C-n>", { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<Leader>w', ':w<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', 'tn', '<esc>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<Leader>x', ':wq!<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<Leader><Leader>x', ':qa!<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<Leader>r', ':source $MYVIMRC<CR>', { noremap = true})
vim.api.nvim_set_keymap('n', '<Leader><Leader>p', ':PackerInstall<CR>', { noremap = true})
vim.api.nvim_set_keymap('n', '<Leader>e', ':edit $MYVIMRC<CR>', { noremap = true, silent = true})
--close window
vim.api.nvim_set_keymap('n', '<Leader><Leader>h', ':clo!<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader><Leader>g', ':Telescope live_grep<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader>f', ':NERDTree<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader>g', ':Telescope current_buffer_fuzzy_find<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '<Left>', 'h', { noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '<Down>', 'j', { noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '<Up>', 'k', { noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '<Right>', 'l', { noremap = true, silent = true})


-- You don't need to set any of these options.

vim.api.nvim_create_autocmd({"BufWinEnter", "WinEnter"}, {   
    pattern = "term://*",
    command = "StartInsert", 
})

--TODO:
--new terminal entered into, opened in an h split
vim.api.nvim_set_keymap('n', '<Leader>t', ':10split +term<CR>', { noremap = true, silent = true})
--buffer
vim.api.nvim_set_keymap('n', '<Leader>n', ':bn<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader>l', ':bp<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader>h', ':bw<CR>', { noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<Leader><Leader>b', ':ls<CR>', { noremap = true, silent = true})
--split
vim.api.nvim_set_keymap('n', '<Leader>s', ':split<CR>', { noremap = true, silent = true})
--next window
vim.api.nvim_set_keymap('n', '<Leader><Leader>n', ':winc w<CR>', { noremap = true, silent = true})
--prev window
vim.api.nvim_set_keymap('n', '<Leader><Leader>l', ':winc W<CR>', { noremap = true, silent = true})


-- Packer plugins
return require('packer').startup(function(use)     
    use 'wbthomason/packer.nvim' -- Packer manages itself      
    -- Plugin examples     
    use 'nvim-lua/plenary.nvim'
    use {
        'nvim-telescope/telescope.nvim', tag = '0.1.6',
        requires = { { 'nvim-lua/plenary.nvim' } }

    }
    use {
        "nvim-telescope/telescope-file-browser.nvim",
        requires = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" }
    }
    use 'mhinz/vim-startify'
    use 'nvim-treesitter/nvim-treesitter' -- Enhanced syntax highlighting     
    use 'mfussenegger/nvim-jdtls'
    use 'hrsh7th/vim-vsnip'
    use 'hrsh7th/vim-vsnip-integ'
    use 'neovim/nvim-lspconfig' -- Language server protocol configurations     
    use 'hrsh7th/cmp-nvim-lsp'
    use 'hrsh7th/cmp-buffer'
    use 'hrsh7th/cmp-path'
    use 'hrsh7th/cmp-cmdline'
    use 'hrsh7th/nvim-cmp' -- Autocompletion     

    use 'scrooloose/nerdtree' -- File explorer     
    use { "ellisonleao/gruvbox.nvim" }
    use { "williamboman/mason.nvim" }
    use "williamboman/mason-lspconfig.nvim"
    use "williamboman/nvim-lsp-installer"

    require 'nvim-treesitter.install'.prefer_git = false
    require 'nvim-treesitter.install'.compilers = {"gcc","zig", "clang"} 
    require 'nvim-treesitter.configs'.setup {
        ensure_installed = {"python", 
                        "lua",
                        "javascript",  
                        "html",
                        "css",
                        "java", 
                        "c", 
                        "cpp",
                        "sql",
                        "go",
                        "rust", 
                        "bash", 
                        "zig"
                        },
        --highlight = {  enable = true, }, 
    }

    require('telescope').setup()
    -- You don't need to set any of these options.
    -- IMPORTANT!: this is only a showcase of how you can set default options!
    require("telescope").setup {
      extensions = {
        file_browser = {
          theme = "ivy",
          -- disables netrw and use telescope-file-browser in its place
          hijack_netrw = true,
          mappings = {
            ["i"] = {
              -- your custom insert mode mappings
            },
            ["n"] = {
              -- your custom normal mode mappings
            },
          },
        },
      },
    }
-- To get telescope-file-browser loaded and working with telescope,
-- you need to call load_extension, somewhere after setup function:
require("telescope").load_extension "file_browser"


  -- Set up nvim-cmp.
  local cmp = require'cmp'

  cmp.setup({
    snippet = {
      -- REQUIRED - you must specify a snippet engine
      expand = function(args)
        vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
        -- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
        -- require('snippy').expand_snippet(args.body) -- For `snippy` users.
        -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
        -- vim.snippet.expand(args.body) -- For native neovim snippets (Neovim v0.10+)
      end,
    },
    window = {
      -- completion = cmp.config.window.bordered(),
      -- documentation = cmp.config.window.bordered(),
    },
    mapping = cmp.mapping.preset.insert({
      ['<C-b>'] = cmp.mapping.scroll_docs(-4),
      ['<C-f>'] = cmp.mapping.scroll_docs(4),
      ['<C-Space>'] = cmp.mapping.complete(),
      ['<C-e>'] = cmp.mapping.abort(),
      ['<CR>'] = cmp.mapping.confirm({ select = true }), -- Accept currently selected item. Set `select` to `false` to only confirm explicitly selected items.
    }),
    sources = cmp.config.sources({
      { name = 'nvim_lsp' },
      { name = 'vsnip' }, -- For vsnip users.
      -- { name = 'luasnip' }, -- For luasnip users.
      -- { name = 'ultisnips' }, -- For ultisnips users.
      -- { name = 'snippy' }, -- For snippy users.
    }, {
      { name = 'buffer' },
    })
  })

  -- To use git you need to install the plugin petertriho/cmp-git and uncomment lines below
  -- Set configuration for specific filetype.
  --[[ cmp.setup.filetype('gitcommit', {
    sources = cmp.config.sources({
      { name = 'git' },
    }, {
      { name = 'buffer' },
    })
 })
 require("cmp_git").setup() ]]-- 

  -- Use buffer source for `/` and `?` (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline({ '/', '?' }, {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
      { name = 'buffer' }
    }
  })

  -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline(':', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources({
      { name = 'path' }
    }, {
      { name = 'cmdline' }
    }),
    matching = { disallow_symbol_nonprefix_matching = false }
  })

local config = {
   -- cmd = {'"C:/Users/joshu/scoop/apps/jdtls/current/bin/jdtls"'},
   cmd ={'jdtls'},
   root_dir = vim.fs.dirname(vim.fs.find({'gradlew', '.git', 'mvnw'}, { upward = true })[1]),
}
require('jdtls').start_or_attach(config)


  -- Set up lspconfig.
    require("nvim-lsp-installer").setup()
  local capabilities = require('cmp_nvim_lsp').default_capabilities()
  -- Replace <YOUR_LSP_SERVER> with each lsp server you've enabled.
  require('lspconfig')['lua_ls'].setup {
    capabilities = capabilities
  }
  require('lspconfig')['snyk_ls'].setup {
    capabilities = capabilities
  }

  require('lspconfig')['clangd'].setup {
    capabilities = capabilities
  }

  require('lspconfig')['jdtls'].setup {
    capabilities = capabilities
  }

    require("mason").setup()
    require("mason-lspconfig").setup{
        ensure_installed = {"snyk_ls","typos_lsp", "clangd", "lua_ls", "jdtls"},
    }


    --colorscheme setting
    vim.o.background = "dark" -- or "light" for light mode 
    vim.cmd([[colorscheme gruvbox]])

end)


