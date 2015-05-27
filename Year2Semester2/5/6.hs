data Expression =  X |
                  Const Int | 
                  Expression :^: Int |
                  Expression :+: Expression |
                  Expression :-: Expression |
                  Expression :*: Expression
				  deriving (Eq, Show)

derivative :: Expression -> Expression
derivative X = (Const 1)
derivative (Const x) = (Const 0)
derivative (x1 :^: x2) = ((Const x2) :*: (x1 :^: (x2 - 1))) :*: (derivative x1)

derivative (x1 :+: x2) = (derivative x1) :+: (derivative x2)
derivative (x1 :-: x2) = (derivative x1) :-: (derivative x2)
derivative (x1 :*: x2) = ((derivative x1) :*: x2) :+: ((derivative x2) :*: x1)


simplification ((Const 0) :*: p) = Const 0
simplification (p :*: (Const 0)) = Const 0
simplification ((Const 1) :*: p) = p
simplification (p :*: (Const 1)) = p

simplification (Const 0 :+: x) = x
simplification (x :+: Const 0) = x

simplification ((Const x1) :+: (Const x2)) = Const (x1 + x2)
simplification ((Const x1) :*: (Const x2)) = Const (x1 * x2)
simplification ((Const x1) :-: (Const x2)) = Const (x1 - x2)
simplification ((Const x1) :^: x2) = Const (x1 ^ x2)

simplification ((Const 0) :^: _) = (Const 0)
simplification (_ :^: 0) = (Const 1)
simplification (p :^: 1) = p
simplification ((Const 1) :^: _) = (Const 1)
simplification p = p

simplificatExpression :: Expression -> Expression
simplificatExpression (x1 :+: x2) = simplification ((simplificatExpression x1) :+: (simplificatExpression x2))
simplificatExpression (x1 :-: x2) = simplification ((simplificatExpression x1) :-: (simplificatExpression x2))
simplificatExpression (x1 :*: x2) = simplification ((simplificatExpression x1) :*: (simplificatExpression x2))
simplificatExpression (x1 :^: x2) = simplification ((simplificatExpression x1) :^: x2)
simplificatExpression x = x