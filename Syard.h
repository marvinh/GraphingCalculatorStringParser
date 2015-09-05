//
//  Syard.h
//  GraphingCalculator
//
//  Created by Marvin on 5/3/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __GraphingCalculator__Syard__
#define __GraphingCalculator__Syard__

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include "Token.h"
#include "num.h"
#include "lparan.h"
#include "rparan.h"
#include "oper.h"
#include "constants.h"
#include "quickTokenize.h"//stokenize redone with string library
#include "mathfunctions.h"
#include "mathconst.h"
#include "variable.h"
#include "comma.h"

//uses quicktokenize to make infix queue
//error checks include empty input and unknown tokens
queue<Token*>InFix(string s);

//infix to post fix error check mismatched paranthesis and empty input
//many edge cases i beleive are handled except for example (y=max cos x 4)
//will be interpreted as x 4 cos max instead of x cos 4 max
//this can be resolved using proper input (y=max(cos(x),4))
queue<Token*>InFixToPostFix(queue<Token*> inputQ);

//include multiple ways of check if inputQ is invalid
//such as mismatch paranthesis.
//will also determine how many doubles should be use and popped
//depending on the function or operator
//no check for infinity or division by zero because
//i beleive thats handled already and has no effect on the graph
double Evaluation(queue<Token*> inputQ, double& x);

///prints function specifically for postfix but can be used elsewhere
void PostPrint(queue<Token*> p);

#endif /* defined(__GraphingCalculator__Syard__) */
