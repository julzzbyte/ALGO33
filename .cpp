CTrade trade;
datetime TimeCurrent();     
int WaitTime = 05;  // 05 Min.
static int TimeSent;
//int curr_positions=PositionsTotal();
//int OrdersTotal();

void OnTick()
  {
     double Ask=NormalizeDouble(SymbolInfoDouble(_Symbol,SYMBOL_ASK),_Digits);
     double Balance=AccountInfoDouble(ACCOUNT_BALANCE);
     double Equity=AccountInfoDouble(ACCOUNT_EQUITY);
     double Bid=NormalizeDouble(SymbolInfoDouble(_Symbol, SYMBOL_BID),_Digits);
     double PositionProfit=PositionGetDouble(POSITION_PROFIT);
     
     if(PositionsTotal()==0)
     trade.Buy(
     0.01,
     NULL,
     Ask,
     0,(Ask+100 * _Point),
     NULL
     );
     
     

      if (TimeLocal() >= TimeSent + (WaitTime * 60) && Equity<Balance)
         {
              trade.Sell(
              0.02,
              NULL,
              Ask,
              0,(Bid-100 * _Point),
              NULL
              );
     
         }
     
     
   
     
   
  }
