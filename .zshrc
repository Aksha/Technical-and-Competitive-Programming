export OBJC_DISABLE_INITIALIZE_FORK_SAFETY=YES
eval "$(rbenv init -)"
export NVM_DIR="$HOME/.nvm"
[ -s "/usr/local/opt/nvm/nvm.sh" ] && . "/usr/local/opt/nvm/nvm.sh"
[ -s "/usr/local/opt/nvm/etc/bash_completion" ] && . "/usr/local/opt/nvm/etc/bash_completion"
export OBJC_DISABLE_INITIALIZE_FORK_SAFETY=YES
eval "$(rbenv init -)"
export NVM_DIR="$HOME/.nvm"
[ -s "/usr/local/opt/nvm/nvm.sh" ] && . "/usr/local/opt/nvm/nvm.sh"
[ -s "/usr/local/opt/nvm/etc/bash_completion" ] && . "/usr/local/opt/nvm/etc/bash_completion"
export HOMEBREW_GITHUB_API_TOKEN=a951d2adfca9b36a663773f4002c4eb9bc542ab4
export PATH=$PATH:/Applications
export NPM_TOKEN=NpmToken.f36dc76b-a1dd-331b-96a8-4ba7f334d7dc
export PS1='%{%F{green}%}%n%{%f%}%{%F{white}%}@%{%f%}%{%F{green}%}%m %{%F{cyan}%}%1~ %{%f%}%% '
HISTFILE=~/.zsh_history
HISTSIZE=999999999
SAVEHIST=$HISTSIZE
alias mahalo='cd ~/workspace/archipelago/react-native/mahalo/'
alias fb='cd ~/workspace/flatbook'
alias arch='cd ~/workspace/archipelago'
alias home='cd /Users/akshayaravichandran'
alias sim11='cd ~/workspace/archipelago/react-native/mahalo/; yarn react-native run-ios --simulator "iPhone 11"'
alias simx='cd ~/workspace/archipelago/react-native/mahalo/; yarn react-native run-ios --simulator "iPhone X"'
alias sima='cd ~/workspace/archipelago/react-native/mahalo/; yarn react-native run-android'
alias android='cd ~/Repos/archipelago/react-native/mahalo/; yarn run:android --deviceId=94VAY0T939'
alias step1='cd ~/workspace/flatbook/; ./do start'
alias step2='cd ~/workspace/archipelago/react-native/mahalo/; ngrok start www graph admin'
alias step3='cd ~/workspace/archipelago/react-native/mahalo/; STORYBOOK=1 yarn start development'
alias staging='STORYBOOK=1 yarn start preview'
alias gitlg='git log --graph --pretty=format:"%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset" --abbrev-commit'
alias gitb='git branch'
