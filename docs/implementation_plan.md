#implementation plan 

## Feature 1: Add client
**trigger** User selects manage Clients from main menu
prompts the user for Client name. Creates a Client Object.
## Feature 2: Create portfolio
**trigger** User selects "Veiw/Modify Client Portfolios" from main menu
prompts the user for Portfolio name. Creates a Portfolio for Client.
User selects "Manage portfolios" and "add to portfolio" 
prompts user for ticker, number of shares and avg price and adds stock to portfolio.
## Feature 3: display performance of a portfolio
**trigger** User selects "Veiw/Modify Client Portfolios" from main menu.
User selects "display performance" and program displays the growth/loss of his investments across all portfolios.
## Feature 4: Save/Load Client data
**trigger** Program startup (load) and (quit)
Will load Clients, their portfolios and related stock data from a csv file.
When exiting the program, all modifications will be written back to the csv file.


