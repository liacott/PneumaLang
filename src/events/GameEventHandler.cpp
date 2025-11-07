#include <vector>
#include "GameEventHandler.h"

// Resolve next event in queue
void GameEventHandler::resolve_next() {
	// WRITE ME
}

// Add event to end of queue
void GameEventHandler::queue_event(GameEvent ev) {
	queue.push_back(ev);
}

// Add event at a specific index in queue
void GameEventHandler::insert_event_at(int pos, GameEvent ev) {
	queue.insert(queue.begin() + pos, ev);
}

// Remove event at a specific index in queue
void GameEventHandler::remove_event_at(int pos, GameEvent ev) {
	queue.erase(
		remove(queue.begin(), queue.end(), queue[pos]),
		queue.end()
	);
}

// Clear the queue of events without resolving any
void GameEventHandler::clear_queue() {
	queue.clear();
}