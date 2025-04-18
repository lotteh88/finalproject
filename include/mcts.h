// vanilla monte-carlo tree search
#ifndef MCTS_H
#define MCTS_H
#include "nodeManager.h"
#include "bitBoard.h"

using namespace bitboard;

class mcts {
private:

	const double WIN = 1.0;
	const double LOSE = -1.0;
	const double DRAW = 0.5;

public:
	enum exp_mode : int {
		EXPANSION_FULL,
		EXPANSION_SINGLE
	};

	vnode* selection(vnode* root);
	vnode* selection_ai(vnode* const root, double c_puct);
	vnode* expansion(vnode* lfnode, const exp_mode& exp_mode = EXPANSION_FULL);
	Won simulation(vnode* exp_node);
	Won simulation_ai(vnode* exp_node);
	vnode* expansion_ai(vnode* lfnode, const exp_mode& exp_mode);
	void update_prior(vnode* expanded_children);
	void backup(vnode* exp_node, const Won& winner_is);
	bool isTerminal(vnode* node);
	void boardViewer(const Bitboard& boardB, const Bitboard& boardW);
	vnode* createValidChildren(vnode* node, int& child_count);
	vnode* createValidChild(vnode* node, int& child_count);
	// Function to get the best move based on visit count
	vnode* get_best_move(vnode* root_node, const int& mode);
	bool haveValidChild(vnode* node);
	Won check_winner(const Bitboard& blackBoard, const Bitboard& whiteBoard);
	std::vector<Square>  mcts::getValidMoves(Bitboard boardB, Bitboard boardW, bool turn);
};

#endif